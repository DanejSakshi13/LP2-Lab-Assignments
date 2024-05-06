% facts
symptom(fever).
symptom(cold).
symptom(vomitting).
symptom(rashes).
symptom(cough).
symptom(headache).
symptom(chills).

% condition
condition(influenza,[cough,cold,fever]).
condition(dengue,[fever,cold,chills,low_blood_count]).
condition(cold, [cough,fever]).

% rules
diagnose_patient(Symptoms, Diagnosis) :- condition(Diagnosis, Symptoms)

% Query 
:- diagnose_patient([cough,cold,fever], Diagnosis).


