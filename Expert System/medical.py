class MedicalExpertSystem:
    symptoms = set()
    diseases = {
        'measles': ['fever', 'rash', 'cough', 'conjuctivities', 'runny_nose'],
        'german_measles': ['fever', 'headache', 'runny_nose', 'rash'],
        'flu': ['fever', 'headache', 'body_ache', 'conjuctivities', 'chills', 'soar_throat', 'cough', 'runny_nose'],
        'common_cold': ['headache', 'sneezing', 'soar_throat', 'chills', 'runny_nose'],
        'mumps': ['fever', 'swollen_glands'],
        'chicken_pox': ['fever', 'rash', 'body_ache', 'chills'],
        'whooping_cough': ['cough', 'sneezing', 'runny_nose']
    }

    @staticmethod
    def ask_symptoms():
        print("Enter symptoms (one at a time, type 'done' when finished):")
        while True:
            symptom = input()
            if symptom.lower() == 'done':
                break
            MedicalExpertSystem.symptoms.add(symptom)

    @staticmethod
    def diagnose():
        print("Diagnosing...")
        for disease, symptoms in MedicalExpertSystem.diseases.items():
            if set(symptoms).issubset(MedicalExpertSystem.symptoms):
                print(f"The patient likely has {disease}")
                return
        print("Unable to determine the disease.")

# Ask for symptoms
MedicalExpertSystem.ask_symptoms()

# Diagnose the disease based on symptoms
MedicalExpertSystem.diagnose()
