import pandas as pd
import numpy as np

def import_matrix(filename):
    m = pd.read_csv(filename, delimiter = '\t', header = None)
    return np.matrix(m)

def export_matrix(filename, m2):
    m3 = pd.DataFrame(m2)
    m3.to_csv(filename, sep = '\t', header=False, index=False)