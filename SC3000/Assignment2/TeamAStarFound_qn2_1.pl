% Gender Definition
male(prince_charles).
male(prince_andrew).
male(prince_edward).
female(princess_ann).
female(queen_elizabeth).

% Define monarch
monarch(queen_elizabeth).

% Define parent-child relation
parent(queen_elizabeth, prince_charles).
parent(queen_elizabeth, prince_andrew).
parent(queen_elizabeth, prince_edward).
parent(queen_elizabeth, princess_ann).

% Define birth order
older(queen_elizabeth, prince_charles).
older(prince_charles, princess_ann).
older(princess_ann, prince_andrew).
older(prince_andrew, prince_edward).

% Determine birth �older� transitivity
older_than_x(A,B) :- older(A,B).
older_than_x(A,C) :-
	older(A,B), older_than_x(B,C).

% Checks if same gender
same_gender(X,Y) :- ((male(X), male(Y)); (female(X), female(Y))), not(X=Y).

% Check if different gender
different_gender(X,Y) :- male(X), female(Y).

% Checks if same gender and X is older than Y.
same_gender_older(X,Y) :- same_gender(X,Y), older_than_x(X,Y).

% Helper rule to verify correct succession order between two individuals
correct_order(X, Y) :-
    (same_gender_older(X, Y) ; different_gender(X, Y)),
    \+monarch(X), \+monarch(Y).

% Validates the order of a list of royals
valid_order([]).
valid_order([_]).
valid_order([First,Second|Rest]) :-
    correct_order(First, Second),
    valid_order([Second|Rest]).

% Main method to get the valid order of a specific number of royals
get_royal_order(List, Number) :- 
    length(List, Number), 
    valid_order(List).

