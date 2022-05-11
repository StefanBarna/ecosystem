***
**main():** The main function.
***
Tile[][] _grid_ ← null  
generateVegetation(grid) ← Bush  
generateVegetation(grid) ← Carrot  
generateAnimals(grid) ← Bunny  
generateAnimals(grid) ← Wolf  
**while** functionalGrid() **do**  
&nbsp;&nbsp;&nbsp;&nbsp; updateVegetation() ← Bush   
&nbsp;&nbsp;&nbsp;&nbsp; updateVegetation() ← Carrot  
&nbsp;&nbsp;&nbsp;&nbsp; updateAnimal() ← Bunny  
&nbsp;&nbsp;&nbsp;&nbsp; updateAnimal() ← Wolf

***
**generateVegetation():** Generates clusters of a variable Plant onto the inputted grid. Finds the number of clusters, the number of plants per cluster, and the location of each cluster. Then populates the clusters with the variable Plant.
***
**Require:** Plant: Type of plant to populate  
**Require:** grid: Set of Tiles to operate on  
_seeds_ ← grid.size() (20% ± 5%)  
_cores_ ← seeds / (grid.size() (10% ± 5%))  
int[cores] _cluster_ ← 0  
Point[] _clusterLoc_ ← null  
**for** each seed **do**    
&nbsp;&nbsp;&nbsp;&nbsp; cluster[rand] += 1  
**for** each core **do**  
&nbsp;&nbsp;&nbsp;&nbsp; **if** grid[rand][rand] not occupied **and** cluster[core] not 0   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; grid[rand][rand] ← Plant  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; clusterLoc[core] ← (rand, rand)  
**for** each core **do**  
&nbsp;&nbsp;&nbsp;&nbsp; **for** each cluster[core] **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Tile near clusterLoc[core] ← Plant  

***
**generateAnimals():** Generates Animals of a variable species onto the inputted grid. Finds the number of animals to spawn, then spawns them at a random unoccupied location in the grid. 
***
**Require:** Animal: Type of animal to populate  
**Require:** grid: Set of Tiles to operate on  
_count_ ← grid.size() (10% ± 5%)  
**for** each count **do**  
&nbsp;&nbsp;&nbsp;&nbsp; **if** grid[rand][rand] not occupied  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; grid[rand][rand] ← Animal  
***

**functionalGrid():** Finds whether the field continues to be playable. That is, if there is still one animal left on the grid.
***
**Require:** grid: Set of Tiles to operate on  
**for** each Tile **do**  
&nbsp;&nbsp;&nbsp;&nbsp; **if** Tile has Animal  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **return** true  
**return** false  

***
**updateVegetation():** Updates a variable Plant, increasing its age, deleting dry/old plants, and spawning in new vegetation of type Plant. Does not manage interations made by any Animal with the Plant.
***
**Require:** Plant: Type of plant to modify  
**Require:** grid: Set of Tiles to operate on  
**for** each Plant on grid **do**  
&nbsp;&nbsp;&nbsp;&nbsp; Plant.age += 1  
&nbsp;&nbsp;&nbsp;&nbsp; **for** each neighboring Tile **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **if** 3 * (Plant.age - 3) >= rand from 0 to 100  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; grid[neighboring Tile] ← Plant    
&nbsp;&nbsp;&nbsp;&nbsp; **if** Plant.age > 10 **and** 20 + (Plant.age - 10) * 10 >= rand from 0 to 100  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; grid[Plant] ← null     
**for** each empty Tile on grid **do**  
&nbsp;&nbsp;&nbsp;&nbsp; **if** rand from 0 to 100 <= 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; grid[empty Tile] ← Plant  

***
**updateAnimal():** Updates a variable Animal, deciding what action to make. Order of priority: fleeing, hunting, mating, and idling. Manages interactions made by the Animal with any Plant.
***
**Require:** Animal: Type of animal to populate  
**Require:** grid: Set of Tiles to operate on  
**for** each Animal on grid **do**  
&nbsp;&nbsp;&nbsp;&nbsp; Point _velocity_ ← (0, 0)  
&nbsp;&nbsp;&nbsp;&nbsp; **for** each Tile in Animal.sightRange **do**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **if** Tile has predator  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; velocity ← away from predator  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **if** Tile has prey **and** Animal.energy < 70%  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; velocity ← towards prey  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **if** Tile has other Animal with energy > 70%  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; velocity ← towards Animal  
&nbsp;&nbsp;&nbsp;&nbsp; **if** velocity is 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **if** rand from 0 to 100 >= 40  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; velocity ← (rand, rand)  
&nbsp;&nbsp;&nbsp;&nbsp; Animal.move(velocity)  
