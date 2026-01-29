# Python equivalent of change_name
def change_name(s):
    s["name"] = "Mike"

student = {
    "name": "mike",
    "age": 31
}

print(student)

change_name(student)

print(student)