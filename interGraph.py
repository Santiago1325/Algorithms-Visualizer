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
pygame.font.init()
FONT = pygame.font.Font(None, 40)



def rects(line):    #recibe una linea de un .txt
    listRects = []
    PosX = WIDTH-WIDTHRECT
    PosY = HEIGHT
    nums = line.split()
    max = numElements()
    

    for i in reversed(nums):
        HEIGHTRECT = int(i)*(HEIGHT//max)
        rect = (PosX, PosY-HEIGHTRECT, WIDTHRECT, HEIGHTRECT)
        listRects.append(rect)
        PosX -= WIDTHRECT


    return listRects


"""Main"""
def main():

    Sorting = open('Sorting.txt', 'r')
    Indexes = open('Index.txt', 'r')
    Comparisons = open('Comparisons.txt','r')
    Swaps = open('Swaps.txt')
    vec = Sorting.readline()
    misRects = rects(vec)

    pygame.init()
    main_surf = pygame.display.set_mode((WIDTH, HEIGHT))

    while True:
        vec = Sorting.readline()
        idx = Indexes.readline()
        count = numElements()-1
        misRects = rects(vec)
        Comp = FONT.render("Comparisons: "+str(int(Comparisons.readline())+1),True,ORANGE,None)
        Sw = FONT.render("Swaps: "+str(int(Swaps.readline())+0),True,ORANGE,None)
        if len(misRects) == 0:
            break
        #time.sleep(0.2)
        ev = pygame.event.poll()
        if ev.type == pygame.QUIT:
            break
        main_surf.fill((0, 0, 0))
        main_surf.blit(Comp,(0,0))
        main_surf.blit(Sw,(0,30))
        for i in misRects:
            if count == int(idx):
                main_surf.fill(GREEN, i)
                count -= 1
            else:
                main_surf.fill(WHITE, i)
                count -= 1
        pygame.display.flip()
    time.sleep(5)
    Sorting.close()
    Indexes.close()
    

main()