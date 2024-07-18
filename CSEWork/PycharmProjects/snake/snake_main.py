import sys
import random

from settings import Settings

import pygame

pygame.init()

screen = pygame.display.set_mode([1005, 750])


def new_apple():
    apple_x = int(random.randint(0, 66)) * 15
    apple_y = int(random.randint(0, 49)) * 15

    return apple_x, apple_y

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


def update_screen(settings, parts, x_change, y_change, apple):
    screen.fill((0, 0, 0))

    for i in range(len(parts) - 1, -1, -1):
        if i != 0:
            parts[i] = parts[i - 1][:]
        elif i == 0:
            parts[i][0] += x_change * 15
            parts[i][1] += y_change * 15

    for segment in parts:
        pygame.draw.rect(screen, settings.colors[settings.color][0], (segment[0], segment[1], 14, 14))

    pygame.draw.rect(screen, (225, 0, 0), (apple[0], apple[1], 15, 15))

    pygame.display.flip()

    run = check_loss(parts)

    return parts, run


def main():
    run = True

    settings = Settings()

    segments = []
    segments.append([495, 330])
    segments.append([480, 330])
    segments.append([465, 330])

    delta_x = 1
    delta_y = 0

    apple_x,  apple_y = new_apple()
    apple = [apple_x, apple_y]

    score = 0

    while run:
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
                    sys.exit()

        print("apple: " + str(apple))
        print("head: " + str(segments[0]))

        if check_eat_apple(segments, apple):
            score += 1
            apple_x, apple_y = new_apple()
            if [apple_x, apple_y] in segments:
                apple_x, apple_y = new_apple()
            apple = [apple_x, apple_y]

            segments.append([segments[len(segments) - 1][0] + (segments[len(segments) - 1][0] - segments[len(segments) - 2][0]), segments[len(segments) - 1][1] + (segments[len(segments) - 1][1] - segments[len(segments) - 2][1])])
            segments.append([segments[len(segments) - 1][0] + (segments[len(segments) - 1][0] - segments[len(segments) - 2][0]), segments[len(segments) - 1][1] + (segments[len(segments) - 1][1] - segments[len(segments) - 2][1])])

        pygame.time.delay(settings.normal_speed)
        segments, run = update_screen(settings, segments, delta_x, delta_y, apple)

    print(score)


main()
