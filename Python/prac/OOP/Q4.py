
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        """Calculate the area of the shape"""
        pass

    @abstractmethod
    def perimeter(self):
        """Calculate the perimeter of the shape"""
        pass

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)
from shapes import Rectangle


rect = Rectangle(10, 5)
print(f"Area of Rectangle: {rect.area()}")
print(f"Perimeter of Rectangle: {rect.perimeter()}")

