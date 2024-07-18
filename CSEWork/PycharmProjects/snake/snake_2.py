import sys
import random

import pygame

from button import Button
from settings import Settings

pygame.init()

screen = pygame.display.set_mode([1005, 750])


def check_loss(parts):

    head = parts[0][:]
    body = parts[1:len(parts)][:]

    for i in range(len(body) - 1):
        if head == body[i]:
            return False

    if (0 >= parts[0][0]) or ((parts[0][0] + 15) >= 1005) or (0 >= parts[0][1]) or ((parts[0][1] + 15) >= 750):
        return False
    else:
        return True


def check_eat_apple(parts, apple):
    if parts[0] == apple:
        return True
    return False


def update_screen(parts, x_change, y_change, apple, color):
    screen.fill((0, 0, 0))

    for i in range(len(parts) - 1, -1, -1):
        if i != 0:
            parts[i] = parts[i - 1][:]
        elif i == 0:
            parts[i][0] += x_change * 15
            parts[i][1] += y_change * 15

    for segment in parts:
        pygame.draw.rect(screen, color, (segment[0], segment[1], 14, 14))

    pygame.draw.rect(screen, (225, 0, 0), (apple[0], apple[1], 15, 15))

    pygame.display.flip()

    run = check_loss(parts)

    return parts, run


def run_game():

    settings = Settings()

    play_button = Button(settings, screen, "Play", 300, 200, 502, 325)

    run = True
    game_active = False

    speed = settings.normal_speed

    segments = []
    segments.append([495, 330])
    segments.append([480, 330])
    segments.append([465, 330])

    delta_x = 1
    delta_y = 0

    apple_x = int(random.randint(0, 67)) * 15
    apple_y = int(random.randint(0, 50)) * 15
    apple = [apple_x, apple_y]

    score = 0

    segments, run = update_screen(segments, delta_x, delta_y, apple, settings.color)

    while run:
        if game_active:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()
                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RIGHT or event.key == pygame.K_d and delta_x != -1:
                        delta_x = 1
                        delta_y = 0
                    elif event.key == pygame.K_LEFT or event.key == pygame.K_a and delta_x != 1:
                        delta_x = -1
                        delta_y = 0
                    elif event.key == pygame.K_DOWN or event.key == pygame.K_s and delta_y != -1:
                        delta_x = 0
                        delta_y = 1
                    elif event.key == pygame.K_UP or event.key == pygame.K_w and delta_y != 1:
                        delta_x = 0
                        delta_y = -1
                    elif event.key == pygame.K_p:
                        game_active = False

            print("apple: " + str(apple))
            print("head: " + str(segments[0]))

            if check_eat_apple(segments, apple):
                score += 1
                apple_x = int(random.randint(0, 67)) * 15
                apple_y = int(random.randint(0, 50)) * 15
                apple = [apple_x, apple_y]

                segments.append([segments[len(segments) - 1][0] + (segments[len(segments) - 1][0] - segments[len(segments) - 2][0]), segments[len(segments) - 1][1] + (segments[len(segments) - 1][1] - segments[len(segments) - 2][1])])

            pygame.time.delay(speed)
            segments, run = update_screen(segments, delta_x, delta_y, apple, settings.color)

        else:
            segments, run = update_screen(segments, delta_x, delta_y, apple, settings.color)
            play_button.draw_button()

            run = True
    print(score)


run_game()
