


def J(theta, x):
    return theta[0] * x + theta[1]**2 - 5

# Goal: find a local minimum of J wrt theta
# Process:
# guess initial value of theta = [theta[0], theta[1]]
# c= 0.001
# compute g = grad J
# theta[0] -= c * g[0]
# theta[1] -= c * g[1]

def grad_J(theta, x):
    return [x, 2*theta[1]]  #[dJ/d theta[0], dJ/d theta[1]

def grad_descent():
    x = 1
    c = 0.001
    theta = [6, 7]
    for i in range(100000):
        g = grad_J(theta, x)
        theta[0] -= c * g[0]
        theta[1] -= c * g[1]
        print("J =", J(theta, x))

grad_descent()