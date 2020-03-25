#!/usr/bin/env python
# coding: utf-8

# In[8]:


import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

data = pd.read_csv('kneeData.csv')

print(data['Knee Position [deg]'])


# In[27]:


p = np.polyfit(range(data.shape[0]), data['Knee Position [deg]'], 15)
x = np.arange(data.shape[0])
eqn = np.polyval(p,x)


plt.figure()
plt.plot(x, data['Knee Position [deg]'], label='Data')
plt.plot(x, eqn, label='Fit')
plt.grid()
plt.legend()
plt.show()


# In[46]:


with open('kneePositionEqn.txt', 'w') as f:
    for i in range(len(p)):
        if i != len(p)-1:
#             print(str(p[i]) + '*pow(x,' + str(len(p)-1 - i) +')' + '+'),
            f.write('(' + str(p[i]) + '*pow(x,' + str(len(p)-1 - i) +')' + ')+'),
        else:
#             print(str(p[i]))
            f.write(str(p[i]))


# In[ ]:





# In[ ]:




