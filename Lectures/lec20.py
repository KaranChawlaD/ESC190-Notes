# # Classes in Python

# class C:
#     def __init__(self, a):
#         self.a = a

#     def add6(self):
#         self.a += 6

# #main
# # c = C() #equivalent to C *c = (C *)malloc(sizof(C));
# # c.a = 42

# c = C(42)
# c.add6()
# # print(c.a)

# """ 
# typedef struct Student {
#     const char *name;
#     int gpa;
# } """

# class Student:
#     def __init__(self, name, gpa):
#         self.name = name
#         self.gpa = gpa
    
#     def __add__(self, right):
#         return self.gpa + right

# s = Student("mike", 2.9)
# print(s.gpa)
# # s + 123 not defined - want this to mean the gpa + 123
# print(s + 1) # 3.9





# a mutable string in Python

class MutableString:
    def __init__(self, s):
        self.L = list(s)

    def __getitem__(self, key):
        return self.L[key]
    
    def __setitem__(self, key, value):
        self.L[key] = value
    
    def __repr__(self):
        return "".join(self.L)

s1 = MutableString("ESC190")
print(s1.L)
print(s1[2])
s1[0] = 'X'
print(s1.L)
print(s1)