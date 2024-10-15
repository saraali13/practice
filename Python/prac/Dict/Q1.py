my_dict = {'name': 'Alice', 'age': 25, 'city': 'New York'}
my_dict = dict(name='Alice', age=25, city='New York')
my_dict = dict([('name', 'Alice'), ('age', 25), ('city', 'New York')])

keys = ['name', 'age', 'city']
values = ['Alice', 25, 'New York']
my_dict = dict(zip(keys, values)

list_of_lists = [['name', 'Bob'], ['age', 30], ['city', 'San Francisco']]
my_dict = dict(list_of_lists)

nested_dict = {
    'person1': {'name': 'Alice', 'age': 25},
    'person2': {'name': 'Bob', 'age': 30}
} 

my_dict = {
    'fruits': ['apple', 'banana', 'cherry'],
    'vegetables': ['carrot', 'lettuce', 'spinach']
}
my_dict = {
    'fruits': ('apple', 'banana', 'cherry'),
    'vegetables': ('carrot', 'lettuce', 'spinach')
}

