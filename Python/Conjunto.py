#This script is an example of how classes, objects and methods works, using the set theory
#Concepts reviewed: Intersection, Union, Difference, Belonging 


class Conjunto(object):
    '''
    classdocs
    '''
    
    def __init__(self, nums):
        aux = 0
        for i in range(0, len(nums)):
            if nums[i] < 1 or nums[i] > 100:
                print('Inserte nuevamente el conjunto, los números deben estar entre 1 y 100')
                aux = 1
                break
        
        if aux == 0:
            self.numeros = nums
    
    def diferencia(self, c):
            '''Este metodo calcula la diferencia entre el Conjunto que llama al metodo y el conjunto c'''
            
            nums1 = []
            
            for i in range(0, len(c.numeros)):
                if c.numeros[i] not in self.numeros:
                    nums1.append(c.numeros[i])
            for i in range(0, len(self.numeros)):
                if self.numeros[i] not in c.numeros:
                    nums1.append(self.numeros[i])
            
            conjunto1 = Conjunto(nums1)
            
            return conjunto1

    def eliminar(self, num):
        index1 = self.numeros.index(num)
        del self.numeros[index1]
        
    def equals(self, c):
        res = 'True'
        if self.numeros == c.numeros:
            res = 'True'
        else: 
            res = 'False'
        
        return res
    
    def interseccion(self, c):
        
        nums1 = [c.numeros[i] for i in range(0, len(c.numeros)) if c.numeros[i] in self.numeros]
        
        conjuntoNew = Conjunto(nums1)
        
        return conjuntoNew
        

    def introducir(self, num):
        self.numeros.append(num)
        self.numeros.sort()
        
    
    def pertenece(self, num):
        res = 'True'
        
        if num in self.numeros:
            res = 'True'
        else:
            res = 'False'
        
        return res


    def toString(self):
        s = '{'
        
        for i in range(0, len(self.numeros)):
            if i == len(self.numeros)-1:
                s = s + str(self.numeros[i]) + '}'
            else:
                s = s + str(self.numeros[i]) + ', '
        
        return s
        

    def union(self, c):
        nums1 = self.numeros
        
        for i in range(0, len(c.numeros)):
            if c.numeros[i] not in nums1: 
                nums1.append(c.numeros[i])
        
        conjunto1 = Conjunto(nums1)
        
        return conjunto1
                


#Some examples to test the code

c1 = Conjunto([1,2,3,4,5])
print('C1 es: ', c1.toString())
c2 = Conjunto([1,2,3])
print('C2 es: ', c2.toString())

c3 = c1.diferencia(c2)
print('Conjunto con diferencia: ', c3.toString())

c1.eliminar(2)
print('C1 después de eliminar el 2: ', c1.toString())

print('C1 y C2 son iguales? ', c1.equals(c2))

c4 = c1.interseccion(c2)
print('Conjunto con interseccion: ', c4.toString())

c1.introducir(2)

print('C1 después de introducir el 2: ', c1.toString())

print('El 40 pertenece a C2?: ', c2.pertenece(40))

c5 = c1.union(c2)

print('La union de C1 y C2 es: ', c5.toString())

