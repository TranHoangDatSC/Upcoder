def calculate_cost(n):
    if n >= 200:
        return "CAT DIEN"
    elif n < 0:
        return "NHAP SAI"
    elif n <= 50:
        return n * 2500
    elif n <= 100:
        return 50 * 2500 + (n - 50) * 3000
    elif n <= 200:
        return 50 * 2500 + 50 * 3000 + (n - 100) * 5000
        
n = int(input())

result = calculate_cost(n)
print(result)
        
