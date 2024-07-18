import pygame.font


class Settings():
    def __init__(self):
        self.normal_speed = 50

        self.num_lives = 1

        self.difficulty = 3     # 1 is easy, 5 is hard

        self.num_apples = 1

        self.color = 3
        self.colors = [((255, 0, 0), "Red"), ((0, 255, 255), "Yellow"), ((255, 255, 0), "Orange"),((34, 139, 34), "Green"), ((0, 0, 255), "Blue"), ((255, 0, 255), "Purple")]
