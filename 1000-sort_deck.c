#include "deck.h"

/**
 * cardcmp - Comparison function for qsort.
 *
 * @card1: Pointer to the first card.
 * @card2: Pointer to the second card.
 * Return: Negative value if card1 < card2,
 * 0 if card1 == card2, positive if card1 > card2.
*/
int cardcmp(const void *card1, const void *card2)
{
    const card_t *c1 = *((const card_t **)card1);
    const card_t *c2 = *((const card_t **)card2);

    if (c1->kind < c2->kind)
        return -1;
    else if (c1->kind > c2->kind)
        return 1;

    return strcmp(c1->value, c2->value);
}

/**
 * sort_deck - Sorts a deck of cards.
 *
 * @deck: Pointer to the head of the deck.
*/
void sort_deck(deck_node_t **deck)
{
    int i;
    deck_node_t *node = *deck;
    const card_t *cards[52];

    for (i = 0; i < 52 && node != NULL; i++)
    {
        cards[i] = node->card;
        node = node->next;
    }

    qsort(cards, i, sizeof(card_t *), cardcmp);

    node = *deck;
    for (i = 0; i < 52 && node != NULL; i++)
    {
        node->card = cards[i];
        node = node->next;
    }
}
