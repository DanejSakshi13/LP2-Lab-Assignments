response(hello,'hello, how are you?').
response(hi,'hi there').
response(bye,'goodbye').

respond(Input, Output) :- response(Input, Output).

chat :-
    repeat,
    write('> '),
    read_line_to_string(user_input, Input),
    atom_string(InputAtom, Input),
    atom_string(TrimmedInputAtom, Input),
    process_input(TrimmedInputAtom),
    TrimmedInputAtom = 'bye',
    !.

process_input(Input) :-
    respond(Input, Response),
    writeln(Response.)