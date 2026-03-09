# import numpy as np

# A = np.array([[0, 1, 1],
#               [1, 0, 0],
#               [1, 0, 0]], dtype=float)

# # Normalize columns
# M = A / A.sum(axis=0)

# # Start with uniform distribution
# v = np.array([1/2, 1/4, 1/4])

# # Iterate
# for i in range(100):
#     v = M @ v

# print(v)   # [0.5, 0.25, 0.25]

# # 5-page web
# A = np.array([[0, 1, 0, 0, 0],
#               [1, 0, 1, 0, 0],
#               [1, 1, 0, 1, 0],
#               [0, 0, 1, 0, 1],
#               [0, 0, 0, 1, 0]], dtype=float)

# # Normalize columns (careful: if a column sums to 0, the page has no outgoing links)
# col_sums = A.sum(axis=0)
# col_sums[col_sums == 0] = 1   # avoid division by zero
# M = A / col_sums

# v = np.ones(5) / 5
# for i in range(100):
#     v = M @ v

# print(v)
# # Page 2 has the highest rank (most pages link to it)


