import pandas as pd
import numpy as np
import seaborn as sns
from matplotlib import pyplot as plt

df_1 = pd.read_csv('matches.csv')
df_2 = pd.read_csv('deliveries.csv')

#Question 1
match_08 = df_1[df_1['season'] == 2008]
total = match_08.shape[0]
print("Total number of matches conducted in 2008 is: ", total)

#Question 2
city_counts = df_1['city'].value_counts()
max_city_count = city_counts.max()
min_city_count = city_counts.min()
print(f"Maximum matches conducted in a city: {max_city_count}\n")
print(f"Minimum matches conducted in a city: {min_city_count}\n")

#Question 3
print("Total count of matches city wise is: \n", city_counts)

#Question 4
toss = df_1['toss_winner'].value_counts()
max_toss = toss.idxmax() #The idxmax() function returns first occurrence of the max value
min_toss = toss.idxmin() #Same for idxmin()
print("Team which has won maximum number of tosses is: ", max_toss, " and the team which has won minimum number of tosses is: ", min_toss)

#Question 5
toss_dec = df_1['toss_decision'].value_counts()
print("Toss decisions taken by the winning teams are: \n", toss_dec)

#Question 6
res = df_1['result'].value_counts()
print("Number of normal and tie matches are: \n", res.iloc[0], res.iloc[1])

#Question 7
tie_matches = df_1[df_1['result'] == 'tie']
tie_teams = tie_matches[['team1', 'team2']]
tie_teams

#Question 8 and 9
highest_run = df_1.loc[df_1['win_by_runs'].idxmax(), 'winner']
lowest_run = df_1.loc[df_1['win_by_runs'].idxmin(), 'winner']
print(highest_run)
print(lowest_run)

#Question 10
player_awards = df_1['player_of_match'].value_counts()
more_3 = player_awards[player_awards > 3]
print("The players which have more than 3 player awards are: \n",more_3)

#Question 11
print("Most awarded player is: ", player_awards.idxmax())

#Questions 12 and 13
highest_run_venue = df_1.loc[df_1['win_by_runs'].idxmax(), 'venue']
lowest_run_venue = df_1.loc[df_1['win_by_runs'].idxmin(), 'venue']
print(highest_run_venue)
print(lowest_run_venue)

#Question 14
umpires = pd.concat([df_1['umpire1'], df_1['umpire2']]).value_counts()
print(umpires)

#Question 15
matches_ss = df_1['season'].value_counts()
print(matches_ss)

#Question 16
merged_df = df_2.merge(df_1[['id', 'season']], left_on='match_id', right_on='id')
seasonal_runs = merged_df.groupby('season')['total_runs'].sum().reset_index()
seasonal_runs.sort_values(by='season', ascending=True)

#Question 17
print(toss, "\n")

#Question 18
sns.countplot(data=df_1, x='season', hue='toss_decision')
plt.title("Toss Decisions Across Seasons")
plt.show()

#Question 19
dismissal_counts = df_2['dismissal_kind'].value_counts()
sns.barplot(x=dismissal_counts.index, y=dismissal_counts.values)
plt.title("Types of Dismissals")
plt.show()

#Question 20
top_scorers = df_2.groupby('batsman')['batsman_runs'].sum().nlargest(10)
sns.barplot(x=top_scorers.values, y=top_scorers.index)
plt.title("Top 10 Run Scorers in IPL")
plt.show()

#Question 21
sns.barplot(x=player_awards.head(10).values, y=player_awards.head(10).index)
plt.title("Top 10 MOM Award Winners")
plt.show()

#Question 22
team_matches = pd.concat([df_1['team1'], df_1['team2']]).value_counts()
print(team_matches)

#Question 23, 24, 25
played_wins = df_1['winner'].value_counts()
played_win_rate = (played_wins / team_matches) * 100
print(played_win_rate)
print(played_wins)

#Question 26
toss_decisions = df_1.groupby(['toss_winner', 'toss_decision']).size().reset_index(name='count')
print(toss_decisions)
