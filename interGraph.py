import pygame
import time

def numElements():
    file = open('Sorting.txt')
    line = file.readline()
    nums = line.split()
    return len(nums)

WHITE = (255,255,255)
GREEN = (0,255,0)
ORANGE = (255,127,80)
WIDTH = 1000
HEIGHT = 500
WIDTHRECT = WIDTH//numElements()



def rects(line):    #recibe una linea de un .txt
    listRects = []
    PosX = 0
    PosY = HEIGHT
    nums = line.split()
    max = numElements()
    

    for i in nums:
        HEIGHTRECT = int(i)*(HEIGHT//max)
        rect = (PosX, PosY-HEIGHTRECT, WIDTHRECT, HEIGHTRECT)
        listRects.append(rect)
        PosX += WIDTHRECT


    return listRects


"""Main"""
def main():

    miArch = open('Sorting.txt', 'r')
    Indexes = open('Index.txt', 'r')
    AuxIndexes = open('AuxIndex.txt','r')
    vec = miArch.readline()
    misRects = rects(vec)
    #auxCount = numElements()

    pygame.init()
    main_surf = pygame.display.set_mode((WIDTH, HEIGHT))

    while True:
        vec = miArch.readline()
        idx = Indexes.readline()
        #idxAux = AuxIndexes.readline()
        count = 0
        misRects = rects(vec)
        if len(misRects) == 0:
            break
        #time.sleep(0.0001)
        ev = pygame.event.poll()
        if ev.type == pygame.QUIT:
            break
        main_surf.fill((0, 0, 0))
        for i in misRects:
            if count == int(idx):
                main_surf.fill(GREEN, i)
                count += 1
            else:
                main_surf.fill(WHITE, i)
                count += 1
        pygame.display.flip()
    miArch.close()
    Indexes.close()
    AuxIndexes.close()
    

main()