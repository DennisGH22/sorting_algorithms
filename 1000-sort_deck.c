#include "deck.h"

/**
 * card_comp - Get the integer value of a card.
 *
 * @card: Pointer to the card.
 *
 * Return: Integer value of the card.
*/
int card_comp(const card_t *card)
{
	int value;

	if (strcmp(card->value, "Ace") == 0)
		value = 1;
	else if (strcmp(card->value, "10") == 0)
		value = 10;
	else if (strcmp(card->value, "Jack") == 0)
		value = 11;
	else if (strcmp(card->value, "Queen") == 0)
		value = 12;
	else if (strcmp(card->value, "King") == 0)
		value = 13;
	else
		value = atoi(card->value);

	return (value + card->kind * 13);
}

/**
 * swap_cards - Swap two cards in the deck.
 *
 * @a: Pointer to the first card.
 * @b: Pointer to the second card.
*/
void swap_cards(deck_node_t *a, deck_node_t *b)
{
	deck_node_t *prev_a = a->prev;
	deck_node_t *next_b = b->next;

	if (prev_a)
		prev_a->next = b;

	b->prev = prev_a;
	a->next = next_b;

	if (next_b)
		next_b->prev = a;

	a->prev = b;
	b->next = a;
}

/**
 * sort_deck - Sort a deck of cards.
 *
 * @deck: Pointer to the head of the deck.
*/
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *next;

	if (!deck || !(*deck) || !((*deck)->next))
		return;

	current = (*deck)->next;

	while (current)
	{
		next = current->next;

		while (
			current->prev
			&& card_comp(current->prev->card) > card_comp(current->card))
		{
			swap_cards(current->prev, current);

			if (!current->prev)
				*deck = current;
		}

		current = next;
	}
}
