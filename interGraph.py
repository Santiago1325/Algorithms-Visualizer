import pygame
import time

WIDTH = 1800
HEIGHT = 1000
ANCHORECT = 10
EJEY = 1000

def rects(line):    #recibe una linea de un .txt
    listRects = []
    p = 0
    l = HEIGHT
    ejy = EJEY
    nums = line.split()

    for i in nums:
        ejy = EJEY-(int(i)*10)
        rect = ((p+WIDTH/4), ejy, ANCHORECT, (int(i)*10))
        listRects.append(rect)
        l += 1
        p += ANCHORECT + 10

    print(nums)
    return listRects


"""Main"""
def main():
    miArch = open('Sorting.txt', 'r')
    Indexes = open('Index.txt', 'r')
    vec = miArch.readline()
    misRects = rects(vec)
    #miArch.close()

    pygame.init()
    surf_sz = 1000
    main_surf = pygame.display.set_mode((surf_sz*2-100, surf_sz))
    BLACK = (0,0,0)
    GREEN = (0,255,0)

    while True:
        vec = miArch.readline()
        idx = Indexes.readline()
        count = 0
        misRects = rects(vec)
        if len(misRects) == 0:
            break
        time.sleep(0.0001)
        ev = pygame.event.poll()
        if ev.type == pygame.QUIT:
            break

        main_surf.fill((255, 255, 255))
        for i in misRects:
            if count == int(idx):
                main_surf.fill(GREEN, i)
                count += 1
            else:
                main_surf.fill(BLACK, i)
                count += 1

        pygame.display.flip()

    pygame.quit()

main()
