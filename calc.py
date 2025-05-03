def sumar(a, b):
    """Returns the sum of a and b."""
    return a + b

def restar(a, b):
    """Returns the result of subtracting b from a."""
    return a - b

def multiplicar(a, b):
    """Returns the product of a and b."""
    return a * b

def dividir(a, b):
    """Returns the result of dividing a by b."""
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b

print(sumar(10, 5))
print(restar(10, 5))
print(multiplicar(10, 5))
print(dividir(10, 5))
