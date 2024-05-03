% Gender Definitions - Kept for completeness.
male(prince_charles).
male(prince_andrew).
male(prince_edward).
female(princess_ann).
female(queen_elizabeth).

% Monarch Definition
monarch(queen_elizabeth).

% Parent-Child Relations
parent(queen_elizabeth, prince_charles).
parent(queen_elizabeth, prince_andrew).
parent(queen_elizabeth, prince_edward).
parent(queen_elizabeth, princess_ann).

% Birth Order Definitions
older(prince_charles, princess_ann).
older(princess_ann, prince_andrew).
older(prince_andrew, prince_edward).

% Determine if A is older than C using transitivity
older_than(A, C) :- older(A, C).
older_than(A, C) :- older(A, B), older_than(B, C).

% Validates the order of a list of royals based on birth order alone
valid_order([]).
valid_order([_]).
valid_order([First, Second|Rest]) :-
    older_than(First, Second),
    valid_order([Second|Rest]).

% Main method to get the valid order of a specific number of royals
get_royal_order(List, Number) :- 
    length(List, Number), 
    valid_order(List).
