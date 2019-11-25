"""
Retorna 2 listas con las números correspondientes a las elecciones
"""

import pygame
import time
import subprocess
import ColorBars
import interGraph

WHITE = (255,255,255)
GREEN = (0,255,0)
ORANGE = (255,127,80)
WIDTH = 1000
HEIGHT = 500
pygame.font.init()
FONT = pygame.font.Font(None, 40)

def clearFiles():
    Info = open("Info.txt", 'w').close
    Sorting = open('Sorting.txt', 'w').close
    Indexes = open('Index.txt', 'w').close
    Comparisons = open('Comparisons.txt','w').close
    Swaps = open('Swaps.txt','w').close


def botones(opcions):
    rectas = []
    y = 10
    for i in opcions:
        rectas.append(pygame.Rect(0, y, 200, 40))
        y += 45
    return rectas

def menuAlgOpcions():
    algOpcions = ["BubbleSort", "InsertionSort", "SelectionSort", "CocktailSort", "BogoSort", "MaxHeapSort", "MinHeapSort", "CountingSort", "OddEvenSort", "GnomeSort"]   #lista de los algoritmos
    menu_surf = pygame.display.set_mode((WIDTH, HEIGHT))
    while True:
        menu_surf.fill((0, 0, 0))
        botons = botones(algOpcions)
        ev = pygame.event.poll()
        if ev.type == pygame.QUIT:
            break
        elif ev.type == pygame.MOUSEBUTTONDOWN:
            for i in range(len(botons)):
                if botons[i].collidepoint((pygame.mouse.get_pos())):
                    return i+1

        y = 20
        for i in range(len(algOpcions)):
            texto = FONT.render(algOpcions[i], 0, WHITE)

            pygame.draw.rect(menu_surf, GREEN, botons[i])
            menu_surf.blit(texto, (0,y))
            y += 45

        pygame.display.update()

def menuNumElements():
    numElements = ["10", "25", "50", "100", "125", "150", "200", "250", "300", "400", "500"]    #Número elementos el el vector
    menu_surf = pygame.display.set_mode((WIDTH, HEIGHT))
    while True:
        menu_surf.fill((0, 0, 0))
        elements = botones(numElements)
        ev = pygame.event.poll()

        if ev.type == pygame.QUIT:
            break
        elif ev.type == pygame.MOUSEBUTTONDOWN:
            for i in range(len(elements)):
                if elements[i].collidepoint((pygame.mouse.get_pos())):
                    return numElements[i]

        y = 20
        for i in range(len(numElements)):
            texto = FONT.render(numElements[i], 0, WHITE)

            pygame.draw.rect(menu_surf, GREEN, elements[i])
            menu_surf.blit(texto, (0,y))
            y += 45

        pygame.display.update()

def menuEstruct():
    estrucType = ["Con Repetición", "Sin repetición"]
    menu_surf = pygame.display.set_mode((WIDTH, HEIGHT))
    while True:
        menu_surf.fill((0, 0, 0))
        estrucTypeButtons = botones(estrucType)
        ev = pygame.event.poll()

        if ev.type == pygame.QUIT:
            break
        elif ev.type == pygame.MOUSEBUTTONDOWN:
            for i in range(len(estrucTypeButtons)):
                if estrucTypeButtons[i].collidepoint((pygame.mouse.get_pos())):
                    return i+1

        y = 20
        for i in range(len(estrucType)):
            texto = FONT.render(estrucType[i], 0, WHITE)

            pygame.draw.rect(menu_surf, GREEN, estrucTypeButtons[i])
            menu_surf.blit(texto, (0,y))
            y += 45

        pygame.display.update()

def menuOrgVec():
    orgVec = ["Ordenado", "Random", "Invertido"]
    menu_surf = pygame.display.set_mode((WIDTH, HEIGHT))
    while True:
        menu_surf.fill((0, 0, 0))
        opcionVect = botones(orgVec)
        ev = pygame.event.poll()

        if ev.type == pygame.QUIT:
            break
        elif ev.type == pygame.MOUSEBUTTONDOWN:
            for i in range(len(opcionVect)):
                if opcionVect[i].collidepoint((pygame.mouse.get_pos())):
                    return i+1
        y = 20
        for i in range(len(orgVec)):
            texto = FONT.render(orgVec[i], 0, WHITE)

            pygame.draw.rect(menu_surf, GREEN, opcionVect[i])
            menu_surf.blit(texto, (0,y))
            y += 45

        pygame.display.update()

def menuVisualizerType():
    visTypes = ["Piramide", "Barras"]
    menu_surf = pygame.display.set_mode((WIDTH, HEIGHT))
    while True:
        menu_surf.fill((0, 0, 0))
        visTypesButtons = botones(visTypes)
        ev = pygame.event.poll()

        if ev.type == pygame.QUIT:
            break
        elif ev.type == pygame.MOUSEBUTTONDOWN:
            for i in range(len(visTypesButtons)):
                if visTypesButtons[i].collidepoint((pygame.mouse.get_pos())):
                    return visTypes[i]
        y = 20
        for i in range(len(visTypes)):
            texto = FONT.render(visTypes[i], 0, WHITE)

            pygame.draw.rect(menu_surf, GREEN, visTypesButtons[i])
            menu_surf.blit(texto, (0,y))
            y += 45

        pygame.display.update()

def menuVelocidad():
    velocidad = ["Rapido", "Medio", "Lento"]
    menu_surf = pygame.display.set_mode((WIDTH, HEIGHT))
    while True:
        menu_surf.fill((0, 0, 0))
        opcionVelocidad = botones(velocidad)
        ev = pygame.event.poll()

        if ev.type == pygame.QUIT:
            break
        elif ev.type == pygame.MOUSEBUTTONDOWN:
            for i in range(len(opcionVelocidad)):
                if opcionVelocidad[i].collidepoint((pygame.mouse.get_pos())):
                    return velocidad[i]

        y = 20
        for i in range(len(velocidad)):
            texto = FONT.render(velocidad[i], 0, WHITE)

            pygame.draw.rect(menu_surf, GREEN, opcionVelocidad[i])
            menu_surf.blit(texto, (0,y))
            y += 45

        pygame.display.update()

def displayMenus():
    menus = [menuAlgOpcions(), menuEstruct(), menuOrgVec(), menuNumElements()]
    menus1 = [menuVelocidad(), menuVisualizerType()]
    return menus, menus1


def main():
	Arg, vis = displayMenus()
	m = ["./main"]
	for i in Arg:
    		m.append(str(i))
	print(m)
	print(vis)
	proc = subprocess.Popen(m)
	time.sleep(4)
	if vis[1] == "Barras":
    		interGraph.main(vis[0])
	elif vis[1] == "Piramide":
    		ColorBars.main(vis[0])
	clearFiles()
	main()

main()
