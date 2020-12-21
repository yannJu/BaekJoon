#2748

# def fibo(n):
#     if n == 0:
#         return 0
#     elif n == 1:
#         return 1
#     else:
#         return fibo(n - 1) + fibo(n - 2)
#
# n = int(input())
#
# print(fibo(n))

n = int(input())
m_1, m_2, result = 1, 0, 0

for x in range(n):
    result = m_1 + m_2
    m_2 = m_1
    m_1 = result

    print("m_1 = ", m_1, "m_2 = ", m_2, "result = ", result)

print(m_2)
