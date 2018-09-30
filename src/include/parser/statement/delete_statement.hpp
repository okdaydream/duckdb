//===----------------------------------------------------------------------===//
//
//                         DuckDB
//
// parser/statement/delete_statement.hpp
//
// Author: Mark Raasveldt
//
//===----------------------------------------------------------------------===//
#pragma once

#include <vector>

#include "parser/sql_statement.hpp"

#include "parser/abstract_expression.hpp"

namespace duckdb {

class DeleteStatement : public SQLStatement {
  public:
	DeleteStatement() : SQLStatement(StatementType::DELETE) {}
	virtual ~DeleteStatement() {}
	virtual std::string ToString() const { return "Delete"; }
	virtual void Accept(SQLNodeVisitor *v) { v->Visit(*this); }

	std::unique_ptr<AbstractExpression> condition;
	std::unique_ptr<TableRef> table;
};
} // namespace duckdb