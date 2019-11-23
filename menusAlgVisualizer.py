"""
Crea un archivo de texto con todas las opciones elegidas en los menús
"""

import pygame
import time

WHITE = (255,255,255)
GREEN = (0,255,0)
ORANGE = (255,127,80)
WIDTH = 1000
HEIGHT = 500
pygame.font.init()
FONT = pygame.font.Font(None, 40)

def botones(opcions):
    rectas = []
    y = 10
    for i in opcions:
        rectas.append(pygame.Rect(0, y, 200, 40))
        y += 45
    return rectas

def menuAlgOpcions():
    algOpcions = ["BubbleSort", "InsertionSort", "SelectionSort", "CocktailSort", "BogoSort", "MaxHeapSort", "MinHeapSort", "CountingSort", "MergSort", "QuickSort"]   #lista de los algoritmos
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
                    return algOpcions[i]

        y = 20
        for i in range(len(algOpcions)):
            texto = FONT.render(algOpcions[i], 0, WHITE)

            pygame.draw.rect(menu_surf, GREEN, botons[i])
            menu_surf.blit(texto, (0,y))
            y += 45

        pygame.display.update()

def menuNumElements():
    numElements = ["10", "50", "100", "250", "500"]    #Número elementos el el vector
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

def menuOrgVec():
    orgVec = ["Ordenado", "Invertido", "Con repeticiones"]
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
                    return orgVec[i]
        y = 20
        for i in range(len(orgVec)):
            texto = FONT.render(orgVec[i], 0, WHITE)

            pygame.draw.rect(menu_surf, GREEN, opcionVect[i])
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

x = open('menus.txt', 'w')
a = menuAlgOpcions()
b = menuNumElements()
c = menuOrgVec()
d = menuVelocidad()
menus = [a, b, c, d]
for i in menus:
    x.writelines(i + '\n')

x.close()