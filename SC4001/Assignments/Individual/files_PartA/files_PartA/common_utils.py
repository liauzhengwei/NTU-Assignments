### THIS FILE CONTAINS COMMON FUNCTIONS, CLASSSES

import tqdm
import time
import random 
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import librosa
import os

import torch
from torch import nn
from torch.utils.data import Dataset
from torch.utils.data import DataLoader

from scipy.io import wavfile as wav

from sklearn import preprocessing
from sklearn.model_selection import KFold
from sklearn.model_selection import train_test_split
from sklearn.metrics import f1_score, precision_score, recall_score, confusion_matrix



def split_dataset(df, columns_to_drop, test_size, random_state):
    label_encoder = preprocessing.LabelEncoder()

    df['label'] = label_encoder.fit_transform(df['label'])

    df_train, df_test = train_test_split(df, test_size=test_size, random_state=random_state)

    df_train2 = df_train.drop(columns_to_drop,axis=1)
    y_train2 = df_train['label'].to_numpy()

    df_test2 = df_test.drop(columns_to_drop,axis=1)
    y_test2 = df_test['label'].to_numpy() 

    return df_train2, y_train2, df_test2, y_test2

def preprocess_dataset(df_train, df_test):

    standard_scaler = preprocessing.StandardScaler()
    df_train_scaled = standard_scaler.fit_transform(df_train)

    df_test_scaled = standard_scaler.transform(df_test)

    return df_train_scaled, df_test_scaled

def set_seed(seed = 0):
    '''
    set random seed
    '''
    random.seed(seed)
    torch.manual_seed(seed)
    np.random.seed(seed)
    torch.cuda.manual_seed_all(seed)
    torch.backends.cudnn.deterministic = True

def extract_features(filepath):
    
    '''
    This function reads the content in a directory and for each audio file detected
    reads the file and extracts relevant features using librosa library for audio
    signal processing
    '''
    # Reading audio file
    y, sr = librosa.load(filepath, mono=True)
    chroma_stft = librosa.feature.chroma_stft(y=y, sr=sr)
    rms = librosa.feature.rms(y=y)
    spec_cent = librosa.feature.spectral_centroid(y=y, sr=sr)
    spec_bw = librosa.feature.spectral_bandwidth(y=y, sr=sr)
    rolloff = librosa.feature.spectral_rolloff(y=y, sr=sr)
    zcr = librosa.feature.zero_crossing_rate(y)
    harmony, perceptr = librosa.effects.harmonic(y), librosa.effects.percussive(y)
    tempo, _ = librosa.beat.beat_track(y=y, sr=sr)
    mfcc = librosa.feature.mfcc(y=y, sr=sr, n_mfcc=20)

    onset_frames = librosa.onset.onset_detect(y=y, sr=sr)
    frames_to_time = librosa.frames_to_time(onset_frames[:20], sr=sr)

    features = [
                f"{filepath}",
                np.mean(chroma_stft), np.var(chroma_stft),
                np.mean(rms), np.var(rms),
                np.mean(spec_cent), np.var(spec_cent),
                np.mean(spec_bw), np.var(spec_bw),
                np.mean(rolloff), np.var(rolloff),
                np.mean(zcr), np.var(zcr),
                np.mean(harmony), np.var(harmony),
                np.mean(perceptr), np.var(perceptr),
                float(tempo)
            ]

    for coeff in mfcc:
        features.append(np.mean(coeff))
        features.append(np.var(coeff))

    columns=['filename',
         'chroma_stft_mean', 'chroma_stft_var',
         'rms_mean', 'rms_var',
         'spectral_centroid_mean', 'spectral_centroid_var',
         'spectral_bandwidth_mean', 'spectral_bandwidth_var',
         'rolloff_mean', 'rolloff_var',
         'zero_crossing_rate_mean','zero_crossing_rate_var',
         'harmony_mean', 'harmony_var',
         'perceptr_mean', 'perceptr_var',
         'tempo'] + \
         [f'mfcc{i+1}_{stat}' for i in range(20) for stat in ['mean', 'var']]

    feature_set = pd.DataFrame([features], columns=columns)
         
    return feature_set


# early stopping obtained from tutorial
class EarlyStopper:
    def __init__(self, patience=3, min_delta=0):
        self.patience = patience
        self.min_delta = min_delta
        self.counter = 0
        self.min_validation_loss = np.inf

    def early_stop(self, validation_loss):
        if validation_loss < self.min_validation_loss:
            self.min_validation_loss = validation_loss
            self.counter = 0
        elif validation_loss > (self.min_validation_loss + self.min_delta):
            self.counter += 1
            if self.counter >= self.patience:
                return True
        return False


# class MLP(nn.Module):
#     def __init__(self, input_dim, hidden_neurons=128):  # Add hidden_neurons as an argument
#         super(MLP, self).__init__()
#         self.model = nn.Sequential(
#             nn.Linear(input_dim, hidden_neurons),  # First hidden layer now uses hidden_neurons
#             nn.ReLU(),
#             nn.Dropout(0.2),
#             nn.Linear(hidden_neurons, 128),  # Keep second and third layers fixed for consistency
#             nn.ReLU(),
#             nn.Dropout(0.2),
#             nn.Linear(128, 128),
#             nn.ReLU(),
#             nn.Dropout(0.2),
#             nn.Linear(128, 1),
#             nn.Sigmoid()
#         )

#     def forward(self, x):
#         return self.model(x)
    
#To display logits
class MLP(nn.Module):
    def __init__(self, input_dim=57, hidden_sizes=[256, 128, 64, 32]):  
        super(MLP, self).__init__()
        
        # Build layers dynamically based on hidden_sizes
        layers = []
        current_input_size = input_dim
        
        # Add hidden layers with tapering pattern
        for hidden_size in hidden_sizes:
            layers.append(nn.Linear(current_input_size, hidden_size))
            layers.append(nn.ReLU())
            layers.append(nn.Dropout(0.2))
            current_input_size = hidden_size
        
        # Add output layer
        layers.append(nn.Linear(current_input_size, 1))
        layers.append(nn.Sigmoid())
        
        self.mlp_stack = nn.Sequential(*layers)

    def forward(self, x, return_logits=False):
        if return_logits:
            # Remove the last sigmoid layer to get logits
            layers = list(self.mlp_stack.children())[:-1]  # All layers except sigmoid
            x = nn.Sequential(*layers)(x)
            logits = x
            prob = torch.sigmoid(logits)
            return (logits, prob)
        else:
            return self.mlp_stack(x)



# Define a dataset class to avoid redundant definitions
class AudioDataset(Dataset):
    def __init__(self, X, y):
        # Ensure X is a tensor
        self.X = torch.tensor(X, dtype=torch.float32) if not isinstance(X, torch.Tensor) else X

        # Handle y: check if it's a Pandas Series/DataFrame or a Tensor
        if isinstance(y, torch.Tensor):
            self.y = y.float().view(-1, 1)  # Ensure it's float and correctly shaped
        elif hasattr(y, "to_numpy"):
            self.y = torch.tensor(y.to_numpy().reshape(-1, 1), dtype=torch.float32)  # Keep old behavior
            
        ### ===========The line below is changed=============
        else:   # Assume is already NumPy array
            self.y = torch.tensor(y.reshape(-1,1), dtype=torch.float32)            

    def __len__(self):
        return len(self.y)

    def __getitem__(self, idx):
        return self.X[idx], self.y[idx]


