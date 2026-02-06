def stack_push(stack, item):
    stack.append(item)

def stack_pop(stack):
    return stack.pop()

def stack_isempty(stack):
    return len(stack) == 0

def make_stack():
    return []

s = make_stack()
stack_push(s, "hi")
stack_push(s, "calculus")
print(stack_pop(s))
print(stack_pop(s))

s = make_stack()
L = ["episilon", "delta", "integral", "series"]
for e in L:
    stack_push(s, e)
while not stack_isempty(s):
    print(stack_pop(s))