# 🧪 SWEAgent Test – Arithmetic Functions

Este repositorio es un experimento para **probar el comportamiento de SWEAgent** frente a un cambio simple en un código de Python.

## 🧠 Contexto

El archivo principal contiene solo dos funciones muy simples:

- `sumar(a, b)` – retorna la suma de `a` y `b`.
- `restar(a, b)` – retorna la resta de `a` y `b`.

El **objetivo del test** fue pedirle a SWE-Agent que:

> "We need new division and multiplication functions with their corresponding prints"

De esta manera evaluamos cómo el agente:
- Interpreta instrucciones sencillas,
- Modifica código existente,
- Añade nuevas funciones manteniendo el estilo y estructura original.



## 📦 Installation

Install dependencies with:
```bash
pip install -r requirements.txt
```

## 🚀 Usage

Example usage of the arithmetic functions:
```python
result = sumar(5, 3)
print(result)  # Output: 8

result = restar(10, 4)
print(result)  # Output: 6
```

Add new functions as needed following the same pattern.

