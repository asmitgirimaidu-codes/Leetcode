import pandas as pd

def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    # Use pandas melt to reshape the DataFrame from wide to long format
    return pd.melt(report, id_vars=['product'], var_name='quarter', value_name='sales')