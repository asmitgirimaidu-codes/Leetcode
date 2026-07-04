import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    # Use the pivot function to reshape the DataFrame
    return weather.pivot(index='month', columns='city', values='temperature')