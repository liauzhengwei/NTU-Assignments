:- discontiguous smartphonetechnology/1.

% Facts
% Both appy and sumsum are companies
company(appy).
company(sumsum).

% stevey is a person
person(stevey).

% galactica-s3 is a smartphone technology
smartphonetechnology(galactica_s3).

% sumsum developed galactica-s3
develop(sumsum,galactica_s3) :- company(sumsum), smartphonetechnology(galactica_s3). 

% stevey stole galactica-s3
steals(stevey,galactica_s3) :- person(stevey), smartphonetechnology(galactica_s3). 

% stevey is the boss of appy
boss(stevey,appy) :- company(appy), person(stevey).

% Inferences
% There are two competing companies
competitor(X,Y) :- company(X), company(Y).

% A rival is a competitor
competitor(X,Y) :- rival(X,Y).
rival(X,Y) :- competitor(X,Y).

% A smartphonetechnology is a business
smartphonetechnology(T):- business(T).
business(T) :- smartphonetechnology(T).

% It is unethical for a boss of a company to steal business from rival companies
unethical(P) :- boss(P,X), steals(P,T), rival(X,Y), develop(Y,T).
