# Moran-Process (Stochastic Evolution of a Population)
The C++ codes for two distinct scenarios of the Moran process in fluctuating environments have been provided.
These codes model the growth of a mutant within a wild-type cell population in a geographically structured population (modeled as a complete graph or circle line), 
aiming to determine the fixation probability and time for the mutant. Essentially, these codes mimic tumor growth within the complex tumor microenvironment. 
The files "BD.cpp" and "BDt.cpp" represent simulations of the birth-death Moran process in spatial and temporal fluctuating environments, respectively. 
Similarly, "DB.cpp" and "DBt.cpp" simulate the death-birth Moran process under the same conditions. 
These codes are primarily used in the research articles "Environmental spatial and temporal variability and its role in non-favoured mutant dynamics" 
and "The effect of spatial randomness on the average fixation time of mutants." 
To execute these codes on Linux, use the command: `g++ -Ofast BD.cpp; ./a.out;` followed by 
entering the population number (e.g., 10, indicating the graph has 10 nodes or the population size is N=10).
Please reference these publications: "https://doi.org/10.1098/rsif.2018.0781", and "https://doi.org/10.1371/journal.pcbi.1005864", if you are using these codes.
For further support, please reach out to [Suzan Farhang-Sardroodi](https://www.suzanfarhangsardroodi.com/).
