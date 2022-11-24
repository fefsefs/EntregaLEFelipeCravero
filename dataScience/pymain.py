import numpy as np
from matplotlib import pyplot as plt
import pandas as pd

# fmt: off

def main():
    # plt.rcParams["figure.figsize"] = [7.00, 3.50]
    # plt.rcParams["figure.autolayout"] = True

    data = pd.read_csv(".\EntregaLE\dataScience\Electric_Vehicle_Population_Data.csv")
    # print(f"{data.isnull().sum()}\n")
    data = data.dropna(subset="State")
    # print(data.isnull().sum())
    # print(data.head())

    states = {"AL": 0,"AK": 0,"AZ": 0,"AR": 0,"CA": 0,"CO": 0,"CT": 0,"DE": 0,"DC": 0,"FL": 0,"GA": 0,"HI": 0,"ID": 0,"IL": 0,"IN": 0,"IA": 0,"KS": 0,"KY": 0,"LA": 0,"ME": 0,"MD": 0,"MA": 0,"MI": 0,"MN": 0,"MS": 0,"MO": 0,"MT": 0,"NE": 0,"NV": 0,"NH": 0,"NJ": 0,"NM": 0,"NY": 0,"NC": 0,"ND": 0,"OH": 0,"OK": 0,"OR": 0,"PA": 0,"RI": 0,"SC": 0,"SD": 0,"TN": 0,"TX": 0,"UT": 0,"VT": 0,"VA": 0,"WA": 0,"WV": 0,"WI": 0,"WY": 0,
    }

    for i in data.State:
        states[i] = states[i] + 1

    stList = sorted(states.items())
    x, y = zip(*stList)
    plt.figure()
    plt.bar(x, y)
    plt.savefig('filename1')

    WACounties = { "Adams": 0, "Asotin": 0, "Benton": 0, "Chelan": 0, "Clallam": 0, "Clark": 0, "Columbia": 0, "Cowlitz": 0, "Douglas": 0, "Ferry": 0, "Franklin": 0, "Garfield": 0, "Grant": 0, "Grays": 0, "Island": 0, "Jefferson": 0, "King": 0, "Kitsap": 0, "Kittitas": 0, "Klickitat": 0, "Lewis": 0, "Lincoln": 0, "Mason": 0, "Okanogan": 0, "Pacific": 0, "Pend Oreille": 0, "Pierce": 0, "San Juan": 0, "Skagit": 0, "Skamania": 0, "Snohomish": 0, "Spokane": 0, "Stevens": 0, "Thurston": 0, "Wahkiakum": 0, "Walla Walla": 0, "Whatcom": 0, "Whitman": 0, "Yakima": 0
    }

    for j in data.County:
        if j in WACounties: WACounties[j] = WACounties[j] + 1
        else: pass
    for v in WACounties:
        if WACounties[v] == 0: WACounties.pop(v)
        else: pass

    cntyList = sorted(WACounties.items())
    t, r = zip(*cntyList)
    plt.figure()
    plt.bar(t, r)
    plt.savefig('filename2')

    plt.show()


if __name__ == "__main__":
    main()
