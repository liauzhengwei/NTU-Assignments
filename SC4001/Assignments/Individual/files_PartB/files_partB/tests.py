import torch


def test_category_embedder(embedder_class):
    """Test the embedder_class module with various scenarios."""

    # Test case 1: Basic functionality
    print("Test 1: Basic functionality")
    num_categories = [10, 5, 3]  # 3 categorical features
    embed_dims = [8, 4, 2]  # corresponding embedding dimensions
    embedder = embedder_class(num_categories, embed_dims, emb_dropout=0.1)

    # Create sample categorical data (batch_size=32, num_categorical_features=3)
    batch_size = 32
    x_cat = torch.randint(0, 10, (batch_size, 3))  # Random categorical indices
    x_cat[:, 1] = torch.randint(0, 5, (batch_size,))  # Respect category limits
    x_cat[:, 2] = torch.randint(0, 3, (batch_size,))

    # Forward pass
    output = embedder(x_cat)
    expected_output_dim = sum(embed_dims)  # 8 + 4 + 2 = 14

    print(f"Input shape: {x_cat.shape}")
    print(f"Output shape: {output.shape}")
    print(f"Expected output dim: {expected_output_dim}")
    assert output.shape == (batch_size, expected_output_dim), (
        f"Expected {(batch_size, expected_output_dim)}, got {output.shape}"
    )
    print("✓ Basic functionality test passed\n")

    # Test case 2: Single categorical feature
    print("Test 2: Single categorical feature")
    single_embedder = embedder_class([20], [10])
    x_single = torch.randint(0, 20, (16, 1))
    output_single = single_embedder(x_single)
    assert output_single.shape == (16, 10)
    print("✓ Single feature test passed\n")

    # Test case 3: Edge case - minimum values
    print("Test 3: Edge case with minimum values")
    min_embedder = embedder_class([1], [1])
    x_min = torch.zeros((5, 1), dtype=torch.long)
    output_min = min_embedder(x_min)
    assert output_min.shape == (5, 1)
    print("✓ Minimum values test passed\n")

    print("All tests passed! 🎉")


def test_house_price_regressor(regressor_class):
    """Test the HousePriceRegressor with random tensors."""

    print("Testing HousePriceRegressor...")

    # Define model parameters
    cardinalities = [12, 26, 10, 15]  # month, town, flat_model_type, storey_range
    embed_dims = [6, 13, 5, 8]  # embedding dimensions for each categorical feature
    n_continuous = 6  # number of continuous features
    batch_size = 32

    # Create the model
    model = regressor_class(cardinalities, embed_dims, n_continuous, emb_dropout=0.1)

    # Create random categorical data (respecting cardinalities)
    x_cat = torch.zeros(batch_size, len(cardinalities), dtype=torch.long)
    for i, card in enumerate(cardinalities):
        x_cat[:, i] = torch.randint(0, card, (batch_size,))

    # Create random continuous data (normalized/scaled)
    x_cont = torch.randn(batch_size, n_continuous)

    print(f"Categorical input shape: {x_cat.shape}")
    print(f"Continuous input shape: {x_cont.shape}")

    # Forward pass
    with torch.no_grad():  # No gradients needed for testing
        output = model(x_cat, x_cont)

    print(f"Output shape: {output.shape}")
    print(f"Output type: {output.dtype}")
    print(f"Sample predictions: {output[:5].tolist()}")

    # Assertions
    assert output.shape == (batch_size,), (
        f"Expected shape ({batch_size},), got {output.shape}"
    )
    assert output.dtype == torch.float32, f"Expected float32, got {output.dtype}"
    assert not torch.isnan(output).any(), "Output contains NaN values"
    assert torch.isfinite(output).all(), "Output contains infinite values"

    print("✓ Basic functionality test passed")

    # Test with different batch sizes
    for test_batch_size in [1, 16, 64, 128]:
        x_cat_test = torch.zeros(test_batch_size, len(cardinalities), dtype=torch.long)
        for i, card in enumerate(cardinalities):
            x_cat_test[:, i] = torch.randint(0, card, (test_batch_size,))

        x_cont_test = torch.randn(test_batch_size, n_continuous)

        with torch.no_grad():
            output_test = model(x_cat_test, x_cont_test)

        assert output_test.shape == (test_batch_size,)
        print(f"✓ Batch size {test_batch_size} test passed")

    # Test model parameters
    total_params = sum(p.numel() for p in model.parameters())
    trainable_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
    print("\nModel info:")
    print(f"Total parameters: {total_params:,}")
    print(f"Trainable parameters: {trainable_params:,}")

    print("\nAll HousePriceRegressor tests passed! 🎉")


def print_dataset_info(train_dataset, test_dataset, train_loader, test_loader):
    print("Dataset info:")
    print(f"Train samples: {len(train_dataset):,}")
    print(f"Test samples: {len(test_dataset):,}")

    print(f"Total batches (train): {len(train_loader)}")
    print(f"Total batches (test): {len(test_loader)}")

    # Test the dataset
    sample_batch = next(iter(train_loader))
    x_cat_batch, x_cont_batch, y_batch = sample_batch.values()
    print("\nSample batch shapes:")
    print(f"Categorical: {x_cat_batch.shape}")
    print(f"Continuous: {x_cont_batch.shape}")
    print(f"Target: {y_batch.shape}")
