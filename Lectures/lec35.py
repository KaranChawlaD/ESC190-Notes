class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def make_tree():
    n1 = Node(8)
    n2 = Node(3)
    n3 = Node(10)
    n4 = Node(14)
    n5 = Node(13)

    n1.left = n2
    n1.right = n3
    n3.right = n4
    n4.left = n5
    return n1

def search_BST(root, elem):
    if root == None:
        return False
    if elem < root.val:
        return search_BST(root.left, elem)
    elif elem == root.val:
        return True
    else:
        return search_BST(root.right, elem)
    
def insert_BST(root, elem):
    n = Node(elem)

    if root == None:
        return n

    if elem < root.val:
        if root.left == None:
            root.left = elem
            return root
        insert_BST(root.left, elem)
    
    if elem > root.val:
        if root.right == None:
            root.right = elem
            return root
        insert_BST(root.right, elem)
