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
def main(speed):
    Info = open("Info.txt", 'r')
    Sorting = open('Sorting.txt', 'r')
    Indexes = open('Index.txt', 'r')
    Comparisons = open('Comparisons.txt','r')
    Swaps = open('Swaps.txt','r')
    Title = Info.readline()
    Title = Title[0:len(Title)-1]
    Complexity = Info.readline()
    Complexity = Complexity[0:len(Complexity)-1]
    vec = Sorting.readline()
    misRects = rects(vec)
    if speed == "Lento":
        speed = 0.5
    elif speed == "Medio":
        speed = 0.2
    elif speed == "Rapido":
        speed = 0
    pygame.init()
    main_surf = pygame.display.set_mode((WIDTH, HEIGHT))
    start = time.time()
    while True:
        vec = Sorting.readline()
        idx = Indexes.readline()
        count = numElements()-1
        misRects = rects(vec)
        Comp = FONT.render("Comparisons: "+str(int(Comparisons.readline())+1),True,ORANGE,None)
        Sw = FONT.render("Swaps: "+str(int(Swaps.readline())+0),True,ORANGE,None)
        Tm = FONT.render("Time: "+str(round(time.time()-start-speed,2)), True, ORANGE, None)
        N = FONT.render("Elemets: "+str(numElements()), True, ORANGE, None)
        T = FONT.render(Title, True, ORANGE, None)
        C = FONT.render(Complexity, True, ORANGE, None)
        if len(misRects) == 0:
            break
        time.sleep(speed)
        ev = pygame.event.poll()
        if ev.type == pygame.QUIT:
            break
        main_surf.fill((0, 0, 0))
        for i in misRects:
            if count == int(idx):
                main_surf.fill(GREEN, i)
                count -= 1
            else:
                main_surf.fill(WHITE, i)
                count -= 1
        main_surf.blit(T,(0,0))
        main_surf.blit(C,(0,30))
        main_surf.blit(Comp,(0,60))
        main_surf.blit(Sw,(0,90))
        main_surf.blit(Tm,(0,120))
        main_surf.blit(N,(0,150))
        pygame.display.flip()
    Sorting.close()
    Indexes.close()
    Comparisons.close()
    Swaps.close()
    time.sleep(3)
    
