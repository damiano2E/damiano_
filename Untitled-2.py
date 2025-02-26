with open("signal_rx.txt" , "r") as file:
    signal = [float(line.strip()) for line in file]
print(signal[:10])

reference_sequence = [0 if i % 2 == 0 else -1 for i in range(100)]

print(reference_sequence)

import numpy as np

correlation = np.correlate(signal, reference_sequence, mode='full')

delay = np.argmax(correlation) - (len(reference_sequence) - 1)
print(f"il ritardo (l'inizio del messaggio) è a: {delay} campioni")

import plotly.graph_objects as go
fig = go.Figure()

fig.add_trace(go.Scatter(x=list(range(len(correlation))), y=correlation, mode= 'lines' , name= 'Correlazione'))

fig.update_layout(
    title="Correlazione tra il segnale ricevuto e la sequenza di riferimento", 
    xaxis_title="Indice",
    yaxis_title="Correlazione"
)
fig.show()