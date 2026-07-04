import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    # Filter, sort, and select using method chaining in a single line
    return animals[animals['weight'] > 100].sort_values(by='weight', ascending=False)[['name']]