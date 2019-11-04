import pygame

ANCHORECT = 20
EJEY = 240

def rects(line):    #recibe una linea de un .txt
    listRects = []
    x = 1
    y = 50
    ejy = EJEY
    nums = line.split()

    for i in nums:
        ejy = EJEY-(int(i)*10)
        rect = (y, ejy, ANCHORECT, (int(i)*10))
        listRects.append(rect)
        x += 1
        y += ANCHORECT + 10

    print(nums)
    return listRects


def mainRelleno():
    pygame.init()

    surf_sz = 480
    main_surf = pygame.display.set_mode((surf_sz, surf_sz))
    small_rect = (300, 200, 150, 90)
    some_color = (255,0,0)

    while True:
        ev = pygame.event.poll()
        if ev.type == pygame.QUIT:
            break

        main_surf.fill((0, 200, 250))
        main_surf.fill(some_color, small_rect)
        pygame.display.flip()

    pygame.quit()

"""Main"""
def main():
    miArch = open('Sorting.txt', 'r')
    vec = miArch.readline()
    misRects = rects(vec)
    miArch.close()

    pygame.init()
    surf_sz = 480
    main_surf = pygame.display.set_mode((surf_sz, surf_sz))
    some_color = (255,0,0)

    while True:
        ev = pygame.event.poll()
        if ev.type == pygame.QUIT:
            break

        main_surf.fill((0, 200, 250))
        for i in misRects:
            main_surf.fill(some_color, i)

        pygame.display.flip()

    pygame.quit()

main()
