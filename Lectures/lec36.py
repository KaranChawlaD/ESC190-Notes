
# Implement a "dictionary" with a list
# grades["bob"] = 97

def str_to_int(s):
    '''Compute an integer that corresponds to the string s
    that's almost unique'''
    # get the ascii value for each character, and compute a VERY large index that corresponds to the combination of those values
    p = 17
    ind = 0
    for i in range(len(s)):
        ind += p**i * ord(s[i])
    return ind


class ArrayMap:
    def __init__(self, capacity):
        self.capacity = capacity
        self.data = [None] * capacity
    
    def get(self, key):
        ind = str_to_int(key)
        return self.data[ind]
    
    def put(self, key, value):
        ind = str_to_int(key)
        if ind > self.capacity:
            data_copy = self.data.copy()
            self.data = [None] * (ind + 1)
            self.data[:len(data_copy)] = data_copy
            self.capacity = ind + 1
        self.data[ind] = value

my_grades = ArrayMap(1000000)
my_grades.put("bob", 90)
print(my_grades.get("bob"))