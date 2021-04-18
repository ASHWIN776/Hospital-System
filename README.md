# Hospital-System
### Simple Hospital System that I coded with C++
---
#### About
- There are 20 different specialization
    - For each specialization, there are only 5 available spots
- Adding a patient
    - Read the requested specialization
    - Read his name and status (0 = regular, 1 urgent)
    - If 5 patients exist, apologize and don’t accept.
    - If the user is regular, add in end of queue. Otherwise, add in the start
- Print patients for the specializations that have waiting patients
- Dr pickup a patient
    - Read the requested specialization. If no patients, inform the doctor.
    - Otherwise, ask the patient to go with the Dr. Remove from the queue.