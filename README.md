# Moran-Process (Stochastic Evolution of a Population)
## The Moran process is a mathematical model used to describe the evolution of genetic types in a population, particularly within the framework of evolutionary game theory. It represents a simplified way to model the dynamics of populations where the total size remains constant, but the composition of types (e.g., different genetic variants or strategies) can change over time. The process is stochastic, meaning it incorporates randomness, and is used to understand how certain traits or strategies become fixed or lost in populations.

### Birth-Death Scenario

In the birth-death scenario of the Moran process, at each step, an individual is chosen for reproduction with a probability proportional to its fitness (the "birth" part). The offspring of this individual then replaces a randomly selected individual in the population (the "death" part). This model emphasizes that the fitter individuals have a higher chance of reproducing before any individual is randomly chosen to be replaced. The order here is crucial: selection based on fitness occurs first, followed by the random elimination of an individual.

### Death-Birth Scenario

Conversely, in the death-birth scenario, an individual is first chosen at random to be removed from the population (the "death" part). Then, one of the remaining individuals is selected to reproduce based on their relative fitness, and the offspring replaces the vacated spot (the "birth" part). This sequence means that the population slot is opened up before competitive reproduction based on fitness takes place.

### Fluctuating Environments

In fluctuating environments, where the fitness of cells or individuals changes both spatially (in different locations) and temporally (over time), the sequence of birth-death vs. death-birth can significantly impact evolutionary outcomes. Since the fitness landscape is dynamic, the timing of selection (before or after a vacancy occurs) can affect which traits or strategies are more likely to spread or become fixed in the population.

- **Spatial Variation**: When fitness varies across different locations, the local competitive environment can dramatically influence which individuals are more likely to reproduce or be replaced. In a birth-death scenario, highly fit individuals in favourable locations can dominate reproduction, while in a death-birth scenario, the opening of a spatial niche by random death allows for potentially diverse strategies to compete based on the current fitness landscape.

- **Temporal Variation**: In environments where fitness changes over time, the order of birth-death vs. death-birth processes can determine how well a population adapts to these changes. For example, in rapidly changing environments, a death-birth process might allow for a more adaptive response by creating opportunities for the selection of individuals that fit under the new conditions immediately after a change occurs.

Understanding the interplay between these processes and environmental fluctuations is key to predicting evolutionary dynamics in natural and artificial populations, including the development of resistance in microbes and the progression of cancerous tumours.

**The C++ codes for two distinct scenarios of the Moran process in fluctuating environments have been provided. These codes model the growth of a mutant within a wild-type cell population in a geographically structured population (modelled as a complete graph or circle line),  aiming to determine the fixation probability and time for the mutant. Essentially, these codes mimic tumour growth within the complex tumour microenvironment.** 

**The files "BD.cpp" and "BDt.cpp" represent simulations of the birth-death Moran process in spatial and temporal fluctuating environments, respectively. 
Similarly, "DB.cpp" and "DBt.cpp" simulate the death-birth Moran process under the same conditions. 
These codes are primarily used in the research articles "Environmental spatial and temporal variability and its role in non-favoured mutant dynamics" 
and "The effect of spatial randomness on the average fixation time of mutants." 
To execute these codes on Linux, use the command: `g++ -Ofast BD.cpp; ./a.out;` followed by 
entering the population number (e.g., 10, indicating the graph has 10 nodes or the population size is N=10).**

# Support

For further support, please reach out to [Suzan Farhang-Sardroodi](https://www.suzanfarhangsardroodi.com/)

# Citation

If you use these codes (BD.cpp, BDt.cpp, DB.cpp, DBt.cpp), please reference these publications: 

[Farhang-Sardroodi, Suzan, Amir H. Darooneh, Mohammad Kohandel, and Natalia L. Komarova. "Environmental spatial and temporal variability and its role in non-favoured mutant dynamics." Journal of The Royal Society Interface 16, no. 157 (2019): 20180781.](https://doi.org/10.1098/rsif.2018.0781),

[Farhang-Sardroodi, Suzan, Amir H. Darooneh, Moladad Nikbakht, Natalia L. Komarova, and Mohammad Kohandel. "The effect of spatial randomness on the average fixation time of mutants." PLoS Computational Biology 13, no. 11 (2017): e1005864.](https://doi.org/10.1371/journal.pcbi.1005864),

or this page: [https://github.com/FarhangSuzan](https://github.com/FarhangSuzan).

