//
// Created by capit on 12/7/2020.
//

#include <queue>
#include "DaySeven.h"

void ExecuteDaySeven()
{
    spdlog::info("Day 7 Challenge");
    spdlog::info("---------------");
    
    std::vector<BagRule> rules = ProcessBagRules("./data/input_day_seven.txt");
    std::vector<std::string> colorTypes;
    CountOfBagsThatContain(rules, "shiny gold", colorTypes);
    uint32_t result = colorTypes.size();
    
    uint32_t resultAlt = CountOfBagsThatMustBeContained(rules, "shiny gold");
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

BagRule ParseBagRule(const std::string& line)
{
    BagRule result;
    
    const std::regex mainRuleCapture("(.*) bags");
    
    std::vector<std::string> tokens = strutil::split(line, " contain ");
    
    std::match_results<std::string::const_iterator> matches;
    if (!std::regex_search(tokens[0], matches, mainRuleCapture))
    {
        spdlog::error("Search for regex failed");
    }
    
    result.BagColor = matches[1].str();
    
    if (tokens[1] != "no other bags.")
    {
        const std::regex subRulesCapture("(\\d+) (.*) bags?");
        std::vector<std::string> subRules = strutil::split(tokens[1], ",");
        
        for (const std::string& subRule : subRules)
        {
            std::match_results<std::string::const_iterator> subRuleMatches;
            if (!std::regex_search(subRule, subRuleMatches, subRulesCapture))
            {
                spdlog::error("Search for regex failed");
            }
            
            result.BagTypes.push_back({stoi(subRuleMatches[1].str()), subRuleMatches[2]});
        }
    }
    
    return result;
}

std::vector<BagRule> ProcessBagRules(const std::string& filename)
{
    std::vector<BagRule> result;
    
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                result.push_back(ParseBagRule(line));
            }
    );
    
    return result;
}

void CountOfBagsThatContain(
        const std::vector<BagRule>& rules, const std::string& bagColor, std::vector<std::string>& colorTypes
)
{
    for (int32_t i = 0; i < rules.size(); i++)
    {
        const BagRule& currentRule = rules[i];
        
        for (int32_t k = 0; k < currentRule.BagTypes.size(); k++)
        {
            if (currentRule.BagTypes[k].second == bagColor)
            {
                if (std::count(colorTypes.begin(), colorTypes.end(), currentRule.BagColor) == 0)
                {
                    colorTypes.push_back(currentRule.BagColor);
                    CountOfBagsThatContain(rules, currentRule.BagColor, colorTypes);
                }
                
                break;
            }
        }
    }
}

int32_t CountOfBagsThatMustBeContained(const std::vector<BagRule>& rules, const std::string& bagColor)
{
    std::queue<std::pair<int32_t, BagRule>> rulesToProcess;
    int32_t count = 0;
    
    auto it = std::find_if(rules.begin(), rules.end(), [&bagColor](const BagRule& x) { return x.BagColor == bagColor; });
    if (it == rules.end())
    {
        return 0;
    }
    
    rulesToProcess.push({1, it[0]});
    
    while (rulesToProcess.size() > 0)
    {
        const BagRule& currentRule = rulesToProcess.front().second;
        for (std::pair<int32_t, std::string> ruleLine : currentRule.BagTypes)
        {
            count += (rulesToProcess.front().first * ruleLine.first);
            const std::string inspectedColor = ruleLine.second;
            
            auto it2 = std::find_if(
                    rules.begin(), rules.end(), [&inspectedColor](const BagRule& x) {
                        return x.BagColor == inspectedColor;
                    }
            );
            if (it2 == rules.end())
            {
                return 0;
            }
            
            rulesToProcess.push({ruleLine.first * rulesToProcess.front().first, it2[0]});
        }
        
        rulesToProcess.pop();
    }
    
    return count;
}
