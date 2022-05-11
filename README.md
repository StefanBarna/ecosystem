## About The Project
This project aims to simulate a micro-ecosystem within the boundaries of a grid. It features a predator (wolf) and prey (bunny) animal in an environment where both must find food ever so often. The project is a zero-player turn by turn simulation. Bunnies must feed on carrots, and wolves must feed on bunnies in order to survive.

### Animal Behaviour
Both bunnies and wolves function in a similar manner, in the sense that both need to receive food every couple turns before being satisfied and wandering about. Each turn, an animal is able to move to any of its surrounding 8 cells, or can choose to stay put. Only one animal is able to occupy a single cell. If a wolf tries to occupy a cell with a bunny in it, it will eat the bunny. A wolf is unable to occupy a cell with another wolf in it. The same goes for bunnies and carrots. All wolves will move in a turn before the bunnies do.

#### Bunnies
A bunny will either run from a wolf, search for food, or move in a random direction (its priorities are in that order). Every 10 turns after eating, a bunny will become hungry. If a bunny is unable to find and eat a carrot 6 turns after becoming hungry, it will die of starvation. If a wolf occupies the same cell as a bunny, the bunny is eaten and dies. Additionally, after eating 2 times, a bunny is capable of reproducing, and will search for a mate. Both a bunny and its mate must have met the criteria of eating 2 carrots in order to reproduce. Once a bunny mates with another bunny, one of the bunnies are randomly selected to become "pregnant", meaning they will produce anywhere from 1 to 5 offspring, where 3 is the most likely amount, after 5 turns. Offspring will spawn in the cells near their parent. A pregnant bunny will become hungry twice as often.

#### Wolves
Wolves function in a similar manner to bunnies, however run on different timers and do not need to run from any predators. Every 20 turns after eating, a wolf will become hungry. If a wolf is unable to capture a bunny 4 turns after becoming hungry, it will die of starvation. When hunting, a wolf is able to _pounce_, meaning that it will move two spaces instead of one in order to secure its food. A wolf is only capable of pouncing once every 15 turns. Additionally, after having eaten 3 times, a wolf is capable of reproduction, and will search for a mate. Both a wolf and its mate must have met the criteria of eating 3 bunnies in order to reproduce. Once a wolf mates with another wolf, one of the wolves are randomly selected to become "pregnant", meaning they will produce either 1 or 2 offspring after 15 turns. Offspring will spawn in the cells near heir parent. A pregnant wolf will become hungry twice as often. After mating, wolves become "bound" to one another, such that both will hunt to feed one another. In other words, if a fed wolf's mate is hungry, both wolves will hunt for a meal.

### Plant Behaviour
Carrots and bush both behave in a similar manner, however provide a different function. Each plant is capable of "spreading", where nearby unoccupied cells are able to take up a new plant. Additionally, each cell has a small chance of becoming a plant tile each turn, where this chance depends on what the plant is.

#### Carrots
Carrots are the only source of food for bunnies. They are capable of spawning on any random tile with a 2% chance. Additionally, a carrot is able to cause other carrots to spring up on nearby tiles. This chance starts at 5%, and will begin to increase after a carrot stays on the grid for more than 3 turns. After the 3rd turn, each neighboring tile's chance of becoming a carrot tile is increased by 3 * (turn_number - 3)%, capping at a maximum chance of 70%. A carrot can not be spawned on a tile occupied by any other item (both animals and plants). If a carrot stays on the grid for longer than 15 turns, it will begin to rot. A rotting carrot has a 20% chance of disappearing from the grid, with an additional 10% for each turn after the 20th.

#### Bushes
Bushes are a source of hiding for bunnies. A bunny hiding in a bush is obscured from vision, and cannot be hunted. Bushes are able to spawn on any random tile with a 3% chance. Additionally, a bush is able to cause other bushes to spring up in nearby tiles. This chance begins at 5%, and will increase by an additional 10% every turn. A bush is able to spawn on any tile unless it is being occupied by another plant. If a bush stays on the grid for 5 turns, it will begin to shrivel. A shriveling bush has a 20% chance of disappearing from the grid, with an additional 10% for every turn after the 5th.
 
## Implementation Brainstorming
| Base Class | Derived Classes |
| ------------ | ----------- |
| Animal Class | Bunny Class |
|              | Wolf Class  |
| Plant Class | Bush Class  |
|              | Grass Class |
| Grid Class |             |

Note that each behaviour and mechanic in this game is open to change in order to balance the project and produce a more longevous simulation.
Note that user interaction will be lateron introduced, allowing the player to add and remove their own plants and animals, after the base game is produced and balanced.

### World 
class that manages the world and grid  
manages animals, vegetation, and environment elements added to the grid  
executes steps in the following order:
- influence all vegetation in order of ID (grow/spread/cull)
- influence all animals in order of ID (move/eat/hunt/hide)


(idea for future workings) weather/seasonal patterns that influence both animal and vegetation activity

### Animal
stores general data about any animal (pure virtual class)  
each animal has a list of foods that it can eat, as well as a list of animals that can eat them  
animals run on an energy bar that, when depleted, causes them to die  
energy can be restored as an animal eats food  
after a certain amount of turns, an animal's energy capacity begins to decrease of old age  
(idea for future workings) animals can have different personalities which may influence how often they may want to eat (regardless of energy) and other mechanics  
each animal has a line of sight, and can only make actions based on what they see  
all animals can reproduce with a partner

#### Derived Animal Classes
store particular data for each individual animal species (only rabbits and wolves right now)

### Vegetation
stores general data about any vegetation (pure virtual class)  
plants are able to sprout at random locations around the map (seeds blown by the wind), and have a significantly larger chance to sprout near locations that have the same plant species on a nearby tile

#### Derived Vegetation Classes
store particular datafor each individual plant species (grass and carrots at the moment)

### Environment
stores general data about any environment details and obstacles  
environment can obstruct pathing, or even line of sight

#### Derived Environment Classes
stores particular data about any environment (eg. rocks/boulders, water/river)  
possible idea for the future: animals can't traverse through water, and plants are more likely to spawn near a body of water
