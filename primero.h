#ifndef LINKED_PRACTICES_H
#define LINKED_PRACTICES_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @file linked_practices.h
 * @brief Prácticas con listas enlazadas - SList ordenada y operaciones avanzadas
 */

/* ========== 1) SList ordenada (simplemente enlazada, enteros) ========== */

/**
 * @struct SNode
 * @brief Nodo de una lista simplemente enlazada ordenada
 * @var key Valor entero del nodo
 * @var next Puntero al siguiente nodo en la lista
 */
struct SNode {
    int key;
    struct SNode* next;
};

/**
 * @struct SList  
 * @brief Lista simplemente enlazada ordenada
 * @var head Puntero al primer nodo de la lista
 * @var size Número de elementos en la lista
 */
struct SList {
    struct SNode* head;
    size_t size;
};

/* ========== OPERACIONES BÁSICAS ========== */

/**
 * @brief Inicializa una lista vacía
 * @param p_list Puntero a la lista a inicializar
 */
void SList_init(struct SList* p_list);

/**
 * @brief Libera todos los nodos de la lista y la deja vacía
 * @param p_list Puntero a la lista a limpiar
 */
void SList_clear(struct SList* p_list);

/**
 * @brief Obtiene el número de elementos en la lista
 * @param p_list Puntero a la lista
 * @return Número de elementos (size_t)
 */
size_t SList_size(const struct SList* p_list);

/**
 * @brief Comprueba si la lista está vacía
 * @param p_list Puntero a la lista
 * @return true si la lista está vacía, false en caso contrario
 */
bool SList_empty(const struct SList* p_list);

/* ========== OPERACIONES DE CONSULTA ========== */

/**
 * @brief Verifica si la lista está ordenada ascendentemente
 * @param p_list Puntero a la lista
 * @return true si está ordenada, false en caso contrario
 */
bool SList_is_sorted(const struct SList* p_list);

/**
 * @brief Busca un nodo con la clave especificada
 * @param p_list Puntero a la lista
 * @param key Clave a buscar
 * @return Puntero al nodo encontrado, o NULL si no existe
 */
struct SNode* SList_find(const struct SList* p_list, int key);

/* ========== OPERACIONES DE MODIFICACIÓN ========== */

/**
 * @brief Inserta una clave manteniendo el orden ascendente
 * @param p_list Puntero a la lista
 * @param key Clave a insertar
 * @return true si se insertó correctamente, false en caso de error
 * @note No inserta claves duplicadas
 */
bool SList_insert_in_order(struct SList* p_list, int key);

/**
 * @brief Elimina el nodo con la clave especificada
 * @param p_list Puntero a la lista
 * @param key Clave a eliminar
 * @return true si se eliminó, false si la clave no existía
 */
bool SList_remove_key(struct SList* p_list, int key);

/* ========== OPERACIONES AVANZADAS ========== */

/**
 * @brief Elimina nodos duplicados consecutivos (lista debe estar ordenada)
 * @param p_list Puntero a la lista
 * @note Mantiene solo la primera ocurrencia de cada clave duplicada
 */
void SList_unique(struct SList* p_list);

/**
 * @brief Invierte el orden de la lista
 * @param p_list Puntero a la lista a invertir
 */
void SList_reverse(struct SList* p_list);

/**
 * @brief Fusiona dos listas ordenadas en la lista destino
 * @param p_dest Lista destino donde se fusionará (debe estar ordenada)
 * @param p_src Lista fuente a fusionar (debe estar ordenada)
 * @note La lista fuente queda vacía después de la fusión
 * @note Ambas listas deben estar ordenadas ascendentemente
 */
void SList_merge_sorted(struct SList* p_dest, struct SList* p_src);

#endif // LINKED_PRACTICES_H