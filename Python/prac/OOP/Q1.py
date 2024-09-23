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
=> Jamal is teacher and is 22 years old
=> Fatima is software developer and is 28 years old
