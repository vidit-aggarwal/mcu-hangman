import pandas as pd
import random
def only_str(var):
    var = var.split(" ", 1)
    var = var[1]
    var = var.strip()
    return var
data = pd.read_csv('characters.csv')
data = data[data.Difficulty == 1]
data = data.reset_index(drop=True)
id = int(random.randrange(0, data.shape[0]-1))
name = data[data.index == id]['Character'].to_string()
name = only_str(name)
realName = data[data.index == id]['Real Name'].to_string()
realName = only_str(realName)
actor = data[data.index == id]['Actor'].to_string()
actor = only_str(actor)
hint = data[data.index == id]['Hint'].to_string()
hint = only_str(hint)
description = name + "'s real name is " + realName +". The characters is played by " + actor +"."
file = open("word.txt", "w")
file.write(name)
file.close()
file = open("description.txt", "w")
file.write(description)
file.close()
file = open("hint.txt", "w")
file.write(hint)
file.close()
