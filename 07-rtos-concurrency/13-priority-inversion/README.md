# Priority Inversion

## What is this topic?
This topic explains the infamous **Priority Inversion** bug, where a High-Priority Task is mathematically blocked from executing by a Medium-Priority Task. 

## Why is it important?
In 1997, NASA's *Mars Pathfinder* spacecraft began randomly resetting itself on the surface of Mars, threatening the $150 million mission. The cause was a textbook Priority Inversion. Understanding this bug and its solution (Priority Inheritance) is a rite of passage for all embedded engineers.

## Prerequisites
- [04-scheduler](../04-scheduler/README.md)
- [08-mutex](../08-mutex/README.md)

## Learning Outcomes
1. Trace the exact sequence of 3 Tasks that causes Priority Inversion.
2. Understand the "Priority Inheritance" algorithm.
3. Understand why Semaphores do not prevent Priority Inversion.
