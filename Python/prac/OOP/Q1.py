class Person:
	name = ‘Jamal’
	occupation =  ‘teacher’
	age = 22

	def info(self):
		print(f”{self.name} is {self.occupation} and is {self.age}
		years old”
a = Person()
a.info()
a.name = ‘Fatima’
a.occupation = ‘software developer’
a.age = 28
a.info()

