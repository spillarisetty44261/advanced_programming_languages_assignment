# Python: Type System Demo - Dynamic Typing

# A variable can change its type at runtime
x = 10
print("Value:", x)
print("Type:", type(x))

# Reassign the same variable to a different type
x = "hello"
print("\nValue:", x)
print("Type:", type(x))

# Reassign again to a float
x = 3.14
print("\nValue:", x)
print("Type:", type(x))

# Type conversion must be EXPLICIT when mixing types
num = 42
text = "The answer is: " + str(num)
print("\n" + text)

# What happens without explicit conversion?
try:
    broken = "The answer is: " + num
except TypeError as e:
    print("TypeError caught:", e)