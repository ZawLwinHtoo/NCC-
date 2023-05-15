from voting_lib import Voting

if __name__ == '__main__':
    voting = Voting()
    voting.loading_db_from_file()
    voting.loading_candidate_from_file()
    for i in range (len(voting.candidate)):
        print(voting.candidate[i])
    print('\n')
    for i in range(len(voting.db)):
        print(voting.db[i])

    voting.main_option()