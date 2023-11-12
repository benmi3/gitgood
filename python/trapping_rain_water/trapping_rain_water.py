
class Solution:
    def trap(self, height: list[int]) -> int:
        water_level = 0
        print(f"{height}")
        check_ = self.thinking_box(height)
        print(f"{check_}")
        lets_see = 0
        lets_see_2 = 0
        for index, item in enumerate(check_):
            print(f"{item}")
            if True in item:
                for index_, item_ in enumerate(item):
                    if index_ > 0:
                        if not item_:
                            if item[index_ - 1]:
                                if index_ < len(item):
                                    lets_see = lets_see + 1
                # -------------------------------------
                    if not item_:
                        if not index_ == 0:
                            print("yay")
                            for x in range(len(item)):
                                if item[index_ - x]:
                                    lets_see_2 = lets_see_2 + 1
                                    break

        print(f"lets_see_2: {lets_see_2}")
        print(f"lets_see: {lets_see}")
        return water_level

    def thinking_box(self, h_: list[int]) -> list[bool]:
        list_clone = h_
        list_looper = False
        list_of_bools = []
        while list_looper == False:
            internal_list = []
            for index_, item in enumerate(list_clone):
                if item == 0:
                    internal_list.append(False)
                else:
                    internal_list.append(True)
                    list_clone[index_] = item - 1
            list_of_bools.append(internal_list)
            if True not in internal_list:
                list_looper = True
                # break
        return list_of_bools # reversed(list_of_bools)


if __name__ == "__main__":
    # height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    height = [4, 2, 0, 3, 2, 5]
    s = Solution()
    water_level = s.trap(height)
    print("----------Finished measuring--------------")
    print(water_level)
